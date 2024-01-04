package main

import (
	"database/sql"
	"fmt"
	_ "github.com/lib/pq"
	"log"
	"os"
)

const (
	host     = "localhost"
	port     = 5432
	user     = "egor"
	password = "YiooSoh5"
	dbname   = "bank_db"
)

func main() {

	infoLog := log.New(os.Stdout, "INFO\t", log.Ldate|log.Ltime)
	errorLog := log.New(os.Stderr, "ERROR\t", log.Ldate|log.Ltime|log.Lshortfile)
	psqlInfo := fmt.Sprintf("host=%s port=%d user=%s "+
		"password=%s dbname=%s sslmode=disable", host, port, user, password, dbname)
	db, err := sql.Open("postgres", psqlInfo)
	if err != nil {
		errorLog.Fatal(err)
	}
	defer db.Close()
	err = db.Ping()
	if err != nil {
		errorLog.Fatal(err)
	}
	infoLog.Println("Established a successful connection")
}
