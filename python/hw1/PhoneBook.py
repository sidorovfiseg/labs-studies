from Contact import Contact
import User
 

class PhoneBook:
  def __init__(self, contact_list : list[Contact], book_tag: str, book_owner: User) -> None:
    self.__contact_list = contact_list
    self.__book_tag = book_tag
    self.__book_owner = book_owner
  
  def __init__(self, book_tag: str, book_owner: User ) -> None:
    self.__contact_list = list()
    self.__book_tag = book_tag
    self.__book_owner = book_owner
  
   
  def add_contact(self, contact: Contact) -> None:
    self.contact_list.append(contact)
  
  def delete_contact(self, contact: Contact) -> None:
    try:
      self.__contact_list.remove(contact)
    except ValueError:
      print("Trying to delete non-existent contact")
  
  def get_contacts_by_country(self, country_code: int) -> list[Contact]:
    contacts = list()
    
    for contact in self.__contact_list:
      if contact.get_country_code() == country_code:
        contacts.append(contact)
    
    return contacts
    
  def get_contacts_by_user(self, user: User) -> list[Contact]:
    contacts = list()
    
    for contact in self.__contact_list:
      if contact.get_owner() == user:
        contacts.append(contact)
    
    return contacts
    
  def rename_book(self, book_tag: str) -> None:
    self.__book_tag = book_tag
    
  def return_owner(self) -> User:
    return self.__book_owner