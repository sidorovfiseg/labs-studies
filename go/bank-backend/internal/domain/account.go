package domain

import "github.com/google/uuid"


type Account struct {
	id uuid.UUID
	name string
	userID uuid.UUID
	balance int
}

// Конструктор нового аккаунта
func NewAccount(id uuid.UUID, name string, balance int, userID uuid.UUID) *Account {
	return &Account{
		id: id, 
		name: name,
		userID: userID,
		balance: balance,
	}
}

func (account * Account) getID() uuid.UUID {
	return account.id
}

func (account *Account) getName() string {
	return account.name
} 

func (account *Account) getUserID() uuid.UUID {
	return account.userID
}

func (account *Account) getBalance() int {
	return account.balance
}
