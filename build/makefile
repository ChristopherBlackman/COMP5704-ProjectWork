build:
	cd src && $(MAKE) build
	cp src/main .

get_data: 
	cd data && $(MAKE) get_data

test_1:
	head data/fake/fake.csv
	./main data/fake/fake.csv , Low High 5
test_2:
	head data/fake/fake1.csv
	./main data/fake/fake1.csv , Low High 5

real_new_york:
	head data/real/USA-road.csv
	./main data/real/USA-road.csv , Low High 5


clean:
	cd src && $(MAKE) clean
	rm -rf main

clean_data:
	cd data && $(MAKE) clean_data
