from .Contact import Contact

class PhoneBook:
  
  def __init__(self, book_tag: str, book_owner) -> None:
    self.__contact_list = list()
    self.__book_tag = book_tag
    self.__book_owner = book_owner
  
  
  def __repr__(self) -> str:
    return f"contact_list: {self.__contact_list}, book_tag: {self.__book_tag}, \
      book_owner: {self.__book_owner}"
  
  def is_contact_exist(self, contact: Contact) -> bool:
    for ex_contact in self.__contact_list:
      if ex_contact == contact:
        return True
    return False
   
  def add_contact(self, contact: Contact) -> None:
    if self.is_contact_exist(contact):
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
    
  
  def get_contacts_by_user(self, user) -> list[Contact]:
    contacts = list()
    
    for contact in self.__contact_list:
      if contact.get_owner() == user:
        contacts.append(contact)
    
    return contacts
    
  def get_contacts(self) -> list[Contact]:
    return self.__contact_list
  
  
  # def rename_book(self, book_tag: str) -> None:
  #   self.__book_tag = book_tag
    
  
  def get_owner(self):
    return self.__book_owner
  
  