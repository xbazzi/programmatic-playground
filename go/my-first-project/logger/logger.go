package logger

import "errors"

func LogSumn(someStr string) (string, error) {
	error := errors.New("u done goofed lol")
	if someStr == "" {
		return "", error
	}
	return someStr, nil
}
