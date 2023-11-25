import uuid 
from book_struct.Contact import Contact
from book_struct.PhoneBook import PhoneBook


class User:
  def __init__(self, name: str) -> None:
    self.__name = name
    self.__friend_list : list[User] = list()
    self.__user_id : uuid.UUID = uuid.uuid4()
    self.__phone_books : dict[str, PhoneBook] = dict() 
  
  
  def __repr__(self) -> str:
    return f"User(name: {self.__name}, friend_list: {self.__friend_list}, \
      user_id: {self.__user_id}, phone_books: {self.__phone_books})"
  
  def __eq__(self, other: 'User') -> bool:
    if isinstance(other, User):
      return self.__user_id == other.get_user_id()
    return False
    
  def __ne__(self, other: 'User') -> bool:
    return not self == other
  
  def get_user_id(self) -> uuid.UUID:
    return self.__user_id
  
  def get_phone_book(self, book_tag: str) -> PhoneBook:
    return self.__phone_books.get(book_tag) 
  
  def add_friend(self, user: 'User') -> None:
    self.__friend_list.append(user)
    
  def delete_friend(self, user: 'User') -> None:
    try:
      self.__friend_list.remove(user)
      print("Successful delete")
    except ValueError:
      print("Trying to delete non-existent friend")
  
  def add_contact(self, contact, book_tag: str) -> None:
    if not self.__phone_books.get(str):
      book = PhoneBook(book_tag, self)
      book.add_contact(contact)
      self.__phone_books.update({book_tag : book})
    else:
      self.__phone_books.get(str).add_contact(contact)
      
  def add_phone_book(self, phone_book, book_tag: str) -> None:
    if self.__phone_books.get(book_tag):
      book = self.__phone_books.get(book_tag)
      for contact in phone_book.get_contacts():
        book.add_contact(contact)
    else:
      self.__phone_books.update({book_tag : phone_book})
      
  
  def is_friend(self, user: 'User') -> bool:
    for friend in self.__friend_list:
      if user == friend:
        return True
    print("Attemting to share with not the friend")
    return False
  
  def is_book_exists(self, book_tag: str) -> bool:
    if self.__phone_books.get(book_tag):
      return True
    print("Book with this tag non-existent")
  
  def share_contact(self, user: 'User', book_tag: str) -> None:
    if self.is_friend(user) and self.is_book_exists(book_tag):
      user.add_phone_book(self.__phone_books.get(book_tag), book_tag)
      
