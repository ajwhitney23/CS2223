all: clean palindrome p2 p3

p2: easy fast

p3: gray

palindrome: palindromecheck.cpp
	g++ palindromecheck.cpp -o palindromecheck

easy: easyinversioncount.cpp
	g++ easyinversioncount.cpp -o easyinversioncount

fast: fastinversioncount.cpp
	g++ fastinversioncount.cpp -o fastinversioncount

gray: graycodesarefun.cpp
	g++ graycodesarefun.cpp -o graycodesarefun

clean:
	rm -f *.o palindromecheck easyinversioncount fastinversioncount graycodesarefun
