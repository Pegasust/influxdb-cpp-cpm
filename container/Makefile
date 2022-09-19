build: prepare
	docker build -t influxdb-cxx:latest .

prepare:
	rm -rf project
	mkdir project
	bash -c "cp -r ../{source,CMakeLists.txt,all,cmake,test,codecov.yaml,standalone,include,documentation} ./project/"

.PHONY: build prepare

