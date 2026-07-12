namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
enum class AccountStatus { troll, guest, user, mod };
enum class Action { read, write, remove };
bool display_post(const AccountStatus& poster, const AccountStatus& viewer) {
  switch (poster) {
    case AccountStatus::troll: {
      if (viewer != AccountStatus::troll)
        return false;
      else
        return true;
    } break;
    default:
      return true;
      break;
  }
}
bool permission_check(const Action& action, const AccountStatus& status) {
  switch (status) {
    case AccountStatus::guest: {
      return action == Action::read;
    } break;
    case AccountStatus::user:
    case AccountStatus::troll: {
      return action != Action::remove;
    } break;
    default:
      return true;
  }
}
bool valid_player_combination(const AccountStatus& player_1,
                              const AccountStatus& player_2) {
  if ((player_1 == AccountStatus::guest) || (player_2 == AccountStatus::guest))
    return false;
  switch (player_1) {
    case AccountStatus::troll:
      return player_2 == AccountStatus::troll;
      break;

    default:
      return player_2 != AccountStatus::troll;
      break;
  }
}
bool has_priority(const AccountStatus& account_1,
                  const AccountStatus& account_2) {
  return account_1 > account_2;
}
// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.

}  // namespace hellmath
