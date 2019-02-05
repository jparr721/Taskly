#include <bullet/note.h>

namespace bullet {
  std::ostream& operator<<(std::ostream& os, Note const& n) {
    os << n.id << ": " << n.type << " " << n.note;

    return os;
  }

  std::string convert_type(const BulletType& t) {
    switch(t) {
      case t::deferred:
        return _config["DEFERRED"]
        break;
      case t::today:
        return _config["TODAY"]
        break;
      case t::future:
        return _config["FUTURE"]
        break;
      case t::goal:
        return _config["GOAL"]
        break;
      case t::event:
        return _config["EVENT"]
        break;
      default:
        return "";
        break;
    }
  }
} //namespace bullet
