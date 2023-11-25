import User

class Contact:
  def __init__(self, country_code: int, number: int, owner: User) -> None:
    self.__country_code = country_code
    self.__number = number
    self.__owner = owner
  
  def __repr__(self) -> str:
    return f"Contact({self.__country_code}, {self.__number}, {self.__owner})"
  
  def get_country_code(self) -> int:
    return self.__country_code
  
  def get_owner(self) -> User:
    return self.__owner
  
  # def __str__(self) -> str:
  #   return f"Contact +{self.__country_code} "
  
  # @staticmethod
  # def _format_number(number: int) -> str:
  #   return "({}) {} {}-{}".format(number )