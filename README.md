[![Build Status][ci_img]][ci_link]
[![Test Coverage][cov_img]][cov_link]
[![Code Quality][cq_img]][cq_link]

[ci_link]: https://travis-ci.org/campisano/cpp_sample_web_scraping_app
[ci_img]: https://travis-ci.org/campisano/cpp_sample_web_scraping_app.svg?branch=master "Build Status"
[cov_link]: https://codecov.io/gh/campisano/cpp_sample_web_scraping_app
[cov_img]: https://codecov.io/gh/campisano/cpp_sample_web_scraping_app/branch/master/graph/badge.svg "Test Coverage"
[cq_link]: https://lgtm.com/projects/g/campisano/cpp_sample_web_scraping_app/context:cpp
[cq_img]: https://img.shields.io/lgtm/grade/cpp/g/campisano/cpp_sample_web_scraping_app.svg?logo=lgtm&logoWidth=18 "Code Quality"

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
