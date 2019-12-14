ARG FROM_IMAGE
FROM $FROM_IMAGE

RUN apt-get -qq update
RUN apt-get -qq -y install libssl1.0.2 libcurl3 > /dev/null
RUN apt-get -qq clean

RUN useradd -r -U app -d /srv/app -m
USER app:app
COPY run.sh /srv/app/run.sh
COPY build /srv/app/build
COPY external /srv/app/external
COPY resources /srv/app/resources

WORKDIR /srv/app
ENTRYPOINT ./run.sh release
