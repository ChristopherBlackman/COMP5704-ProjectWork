build:
	cd src && $(MAKE) build
	cp src/main .

test_1:
	head data/fake/fake1.csv
	./main data/fake/fake1.csv , Low High 5

test_2:
	./main data/fake/fake.csv , Low High 5

clean:
	cd src && $(MAKE) clean
	rm -rf main
