import uuid

class User:
  def __init__(self, name: str) -> None:
    self.__name = name
    self.__friend_list = list()
    self.__user_id = uuid.uuid4()
    self.__phone_book = dict() 
  
  def __eq__(self, other: 'User') -> bool:
    if isinstance(other, User):
      return self.__user_id == other.get_user_id()
    
  def __ne__(self, other: 'User') -> bool:
    return not self == other
  
  def get_user_id(self) -> uuid.UUID:
    return self.__user_id
  
  def add_friend(self, friend: 'User') -> None:
    self.__friend_list.append(friend)
    
  def delete_friend(self, friend: 'User') -> None:
    try:
      self.__friend_list.remove(friend)
    except ValueError:
      print("Trying to delete non-existent friend")