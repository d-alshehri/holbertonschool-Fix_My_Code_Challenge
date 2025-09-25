#!/usr/bin/python3
"""
 User Model
"""
import hashlib
import uuid


class User:
    """
    User class:
    - id: public string unique (uuid)
    - password: private string hash in MD5
    """

    __password = None

    def __init__(self):
        """Initialize a new user with a unique id"""
        self.id = str(uuid.uuid4())

    @property
    def password(self):
        """Password getter"""
        return self.__password

    @password.setter
    def password(self, pwd):
        """Password setter: hashes string input or sets None"""
        if pwd is None or type(pwd) is not str:
            self.__password = None
        else:
            self.__password = hashlib.md5(pwd.encode()).hexdigest().lower()

    def is_valid_password(self, pwd):
        """Check if pwd matches stored hashed password"""
        if pwd is None or type(pwd) is not str:
            return False
        if self.__password is None:
            return False
        return hashlib.md5(pwd.encode()).hexdigest().lower() == self.__password


if __name__ == '__main__':
    print("Test User")
    # your tests remain the same
