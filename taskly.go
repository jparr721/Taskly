package main

import (
	"fmt"

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

func main() {
	app = tview.NewApplication()
	if err := app.Run(); err != nil {
		fmt.Printf("Error running application: %s\n", err)
	}
}

func createTask() {

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
