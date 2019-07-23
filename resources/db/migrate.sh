#!/bin/sh

echo 'waiting for postgres...'
while true
do
    sleep 3s
    /usr/local/bin/flyway -user=$DB_USER -locations=filesystem:/data -password=$DB_PWRD -url="jdbc:postgresql://$DB_HOST:$DB_PORT/$DB_NAME" info 1>/dev/null 2>&1 && break
done

echo "updating $DB_NAME"
/usr/local/bin/flyway -user=$DB_USER -locations=filesystem:/data -password=$DB_PWRD -url="jdbc:postgresql://$DB_HOST:$DB_PORT/$DB_NAME" migrate
