
from .User import User

class Admin(User):
  def __init__(self, name: str) -> None:
    super().__init__(name)
    
  def add_contact(self, contact, book_tag: str, user: User) -> None:
    user.add_contact(contact, book_tag)
  
  def drop_contact(self, contact, book_tag: str, user: User) -> None:

    book = user.get_phone_book(book_tag)  
    if book:
      book.delete_contact(contact)
    else:
      print("This contact already exists")
      