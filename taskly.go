package main

import (
	"fmt"
	"time"

	"github.com/gdamore/tcell"
	"github.com/rivo/tview"
)

const (
	batchSize = 40
	taskPage  = "*task*"
)

var (
	app       *tview.Application
	pages     *tview.Pages
	taskFocus *tview.Primitive
)

type task struct {
	Title       string
	DateAdded   time.Time
	CompletedOn time.Time
}

func main() {
	app = tview.NewApplication()
	if err := app.Run(); err != nil {
		fmt.Printf("Error running application: %s\n", err)
	}
}

func addTask() {
	form := tview.NewFom().
		AddInputField("Title", "", 20, nil, nil).
		AddInputField("Date Added", time.Now(), 20, nil, nil).
		AddButton("Save", nil).
		AddButton("Quit", func() {
			app.Stop()
		})
	form.SetBorder(true).SetTitle("Create a new task").SetTitleAlign(tview.AlignCenter)
	if err := app.SetRoot(form, true).SetFocus(form).Run(); err != nil {
		panic(err)
	}
}

func deleteTask() {
	modal := tview.NewModal().
		SetText("Do you want to delete this task?").
		AddButtons([]string{"Yes", "Cancel"}).
		SetDoneFunc(func(buttonIndex int, buttonLabel string) {
			if buttonLabel == "Yes" {
				// Add the magic here
			}
		})
	if err := app.SetRoot(modal, false).SetFocus(modal).Run(); err != nil {
		panic(err)
	}
}

func loadWindows() {
	// Create basic windows
	actions := tview.NewList().ShowSecondaryText(false)
	actions.SetBorder(true).SetTitle("Actions")
	tasks := tview.NewTable().SetBorders(true)
	tasks.SetBorder(true).SetTitle("Tasks")

	flex := tview.NewFlex().
		AddItem(actions, 0, 1, true).
		AddItem(tasks, 0, 3, true)

	tasks.SetCell(0, 0, &tview.TableCell{Text: "Title", Align: tview.AlignCenter, Color: tcell.ColorYellow}).
		SetCell(0, 1, &tview.TableCell{Text: "Date Added", Align: tview.AlignCenter, Color: tcell.ColorYellow}).
		SetCell(0, 2, &tview.TableCell{Text: "Completed On", Align: tview.AlignCenter, Color: tcell.ColorYellow})
	pages = tview.NewPages().
		AddPage(taskPage, flex, true, true)
	app.SetRoot(pages, true)
}
