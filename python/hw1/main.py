from Contact import Contact
from User import User
from Admin import Admin

def main() -> None:
  user = User("egor")
  user1 = User("olga")
  admin = Admin("petr")
  contact = Contact(7, 9214185787, user)
  contact1 = Contact(7, 9218214546, user1)
  
  user.add_contact(contact, 'work')
  user1.add_contact(contact1, "family")
  user.add_friend(user1)
  user1.add_friend(user)
  user1.share_contact(user, 'family')
  
  print(user)


if __name__ == "__main__":
  main()