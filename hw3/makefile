all: clean palindrome p2 easy2

p2: easy fast

palindrome: palindromecheck.cpp
	g++ palindromecheck.cpp -o palindrome

easy: easyinversioncount.cpp
	g++ easyinversioncount.cpp -o easy

easy2: workingeasyinversioncount.cpp
	g++ workingeasyinversioncount.cpp -o easy2

fast: fastinversioncount.cpp
	g++ fastinversioncount.cpp -o fast

clean:
	rm -f *.o palindrome easy