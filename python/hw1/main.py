from Contact import Contact
from User import User
def main() -> None:
  user = User()
  contact = Contact(7, 9214185787, user)
  
  print(contact)
  


if __name__ == "__main__":
  main()