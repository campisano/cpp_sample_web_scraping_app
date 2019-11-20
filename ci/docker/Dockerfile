FROM debian:stretch-slim

RUN apt-get -q update
RUN apt-get -q -y install libssl1.0.2 libcurl3

RUN mkdir -p /srv/app
COPY run.sh /srv/app/run.sh
COPY build /srv/app/build

WORKDIR /srv/app
ENTRYPOINT ./run.sh release
