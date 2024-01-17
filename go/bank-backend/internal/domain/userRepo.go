package domain

import "context"

type UserRepository interface {
	Save(ctx context.Context, user *User) error
	FindByLogin(ctx context.Context, login string) (*User, error)
}