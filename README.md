###### *Tests:* linux: [![Build Status](https://travis-ci.org/campisano/cpp_sample_web_scraping_app.svg?branch=master "Linux build")](https://travis-ci.org/campisano/cpp_sample_web_scraping_app) [![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/campisano/cpp_sample_web_scraping_app.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/campisano/cpp_sample_web_scraping_app/context:cpp)

---



# C++ sample REST application

An application developed to show a sample solution in c++11 to provide and consume REST API and store data in a RDBMS.

A docker-compose.yml is provided to rapidly have a local database ready to test the project.



## Usage

* Dependencies

```apt-get install gcc g++ make cmake libssl1.0-dev libcurl4-openssl-dev```

* Build

```make```

* Run

```docker-compose up -d```

```./build/debug/scraper```
