###### *Tests:* linux: [![Build Status](https://travis-ci.org/campisano/cpp_sample_web_scraping_app.svg?branch=master "Linux build")](https://travis-ci.org/campisano/cpp_sample_web_scraping_app)

---



# C++ sample REST application

An application developed to show a sample solution in c++11 to provide and consume REST API and store data in a RDBMS.

A docker-compose.yml is provided to rapidly have a local database ready to test the project.



# Usage

* Dependencies

```apt-get install make cmake g++ libcurl4-openssl-dev libpq-dev```

* Build

```make```

* Run

```docker-compose up -d```
```./build/debug/scraper```
