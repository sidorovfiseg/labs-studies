class Contact:
  def __init__(self, country_code: int, number: int, owner) -> None:
    self.__country_code = country_code
    self.__number = number
    self.__owner = owner
  
  def __repr__(self) -> str:
    return f"Contact({self.__country_code}, {self.__number}, {self.__owner})"
  
  def __eq__(self, other: 'Contact') -> bool:
    if isinstance(other, Contact):
      return self.__country_code == other.get_country_code() and self.__number == other.get_number()
    return False
    
  def __ne__(self, other: 'Contact') -> bool:
    return not self == other
  
  
  def get_country_code(self) -> int:
    return self.__country_code
  
  def get_number(self) -> int:
    return self.__number
  
  def get_owner(self):
    return self.__owner
  
  # def __str__(self) -> str:
  #   return f"Contact +{self.__country_code} "
  
  # @staticmethod
  # def _format_number(number: int) -> str:
  #   return "({}) {} {}-{}".format(number )

