USA-road.gr : 
	wget -O USA-road.gr.gz http://users.diag.uniroma1.it/challenge9/data/USA-road-d/USA-road-d.NY.gr.gz
	gzip -d USA-road.gr.gz
	sed -i '1,7d' USA-road.gr
	python3 transform_data.py USA-road.gr USA-road.csv
USA-road-full.gr:
	wget -O USA-road-full.gr.gz http://users.diag.uniroma1.it/challenge9/data/USA-road-d/USA-road-d.USA.gr.gz
	gzip -d USA-road-full.gr.gz
	sed -i '1,7d' USA-road-full.gr
	python3 transform_data.py USA-road-full.gr USA-road-full.csv

clean:
	rm -f *.gr*
	rm -f *.csv

