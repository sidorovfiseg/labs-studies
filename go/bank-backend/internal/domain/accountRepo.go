package domain

import (
	"context"

	"github.com/google/uuid"
)

type AccountRepository interface {
	Save(ctx context.Context, account *Account) error
	FindAccountByName(ctx context.Context, name string, userID uuid.UUID) (*Account, error)
	UpdateAccountBalance(ctx context.Context, id uuid.UUID, deposit int) error
	FindByIDForUpdate(ctx context.Context, id uuid.UUID) (*Account, error)
	FindUserAccountsILike(ctx context.Context, name string, offset int, limit int, userID uuid.UUID) ([]Account, error)
}