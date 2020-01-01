[![Build Status](https://travis-ci.org/campisano/cpp_sample_web_scraping_app.svg?branch=master "Build Status")](https://travis-ci.org/campisano/cpp_sample_web_scraping_app)
[![Test Coverage](https://codecov.io/gh/campisano/cpp_sample_web_scraping_app/branch/master/graph/badge.svg "Test Coverage")](https://codecov.io/gh/campisano/cpp_sample_web_scraping_app)
[![Code Quality](https://img.shields.io/lgtm/grade/cpp/g/campisano/cpp_sample_web_scraping_app.svg "Code Quality")](https://lgtm.com/projects/g/campisano/cpp_sample_web_scraping_app/context:cpp)

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
