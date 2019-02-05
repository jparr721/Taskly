#include <bullet/note.h>

namespace bullet {
  std::ostream& operator<<(std::ostream& os, Note const& n) {
    os << n.id << ": " << n.type << " " << n.note;

    return os;
  }

  std::string Note::convert_type(const BulletType& t) {
    switch(t) {
      case BulletType::deferred:
        return _config["DEFERRED"];
        break;
      case BulletType::today:
        return _config["TODAY"];
        break;
      case BulletType::future:
        return _config["FUTURE"];
        break;
      case BulletType::goal:
        return _config["GOAL"];
        break;
      case BulletType::event:
        return _config["EVENT"];
        break;
      default:
        return "";
        break;
    }
  }
} //namespace bullet
