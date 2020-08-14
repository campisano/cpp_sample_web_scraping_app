ARG FROM_IMAGE
FROM $FROM_IMAGE

RUN apt-get -qq update \
    && apt-get -qq -y install --no-install-recommends apt-utils > /dev/null \
    && apt-get -qq -y install --no-install-recommends make libssl1.0.2 libcurl3 > /dev/null \
    && apt-get -qq clean \
    && rm -rf /var/lib/apt/lists/* /var/cache/apt/archives/* /usr/share/man/*

RUN useradd -r -U app -d /srv/app -m
USER app:app

COPY ./run.sh /srv/app/run.sh
COPY ./build /srv/app/build
COPY ./external /srv/app/external
COPY resources /srv/app/resources

WORKDIR /srv/app
ENTRYPOINT ["./run.sh"]
CMD ["release"]
