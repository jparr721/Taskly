#include "bullet.h"

namespace bullet {
  parser::parser(const int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
      parse(argv[i]);
    }

    flush();
  }

  void parser::parse(const std::string_view& item) {
    item.at(0) == '-' ? flag(item) : value(item)
  }

  void parser::flag(const std::string_view& item) {
    // Strip off flag and keep the word
    flush();
    current_option_ = item;
    current_option_->remove_prefix(current_option_->find_first_not_of('-'));

    // Packed args
    const auto delimiter = current_option_->find_first_not_of('-');
    if (delimiter != std::string_view::npos) {
      auto value = *current_option_;
      value.remove_prefix(delimiter + 1);
      current_option_->remove_suffix(current_option_->size() - delimiter);
      value(value);
    }
  }

  void parser::value(const std::optional<std::string_view>& value) {
    if (!current_option_) {
      positionals_.emplace_back(*value);
    } else {
      optionals_.emplace(*current_option_, value);
      current_option_.reset();
    }
  }

  void parser::flush() {
    if (current_option_) value();
  }

  const option_map& parser::options() const { return optionals_; }

  const std::vector<std::string_view>& parser::positional_arguments() const {
    return positionals_;
  }
}// namespace bullet
