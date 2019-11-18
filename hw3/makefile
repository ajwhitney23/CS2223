all: clean palindrome p2 p3

p2: easy fast

p3: gray

palindrome: palindromecheck.cpp
	g++ palindromecheck.cpp -o palindrome

easy: easyinversioncount.cpp
	g++ easyinversioncount.cpp -o easy

fast: fastinversioncount.cpp
	g++ fastinversioncount.cpp -o fast

gray: graycodesarefun.cpp
	g++ graycodesarefun.cpp -o gray

clean:
	rm -f *.o palindrome easy fast gray
