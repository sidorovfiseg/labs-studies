package domain

import "github.com/google/uuid"

type User struct {
	id uuid.UUID
	login string
	hashPassword []byte
}

func NewUser(id uuid.UUID, login string, password []byte) *User {
	return &User{
		id: id,
		login: login,
		hashPassword: password,
	}
}

func (user *User) getID() uuid.UUID {
	return user.id
}

func (user *User) getLogin() string {
	return user.login
}

func (user *User) getPassword() []byte {
	return user.hashPassword
}