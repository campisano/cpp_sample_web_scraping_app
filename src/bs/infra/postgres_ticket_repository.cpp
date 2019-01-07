#include "postgres_ticket_repository.hpp"

#include <sstream>
#include <sqlpp11/sqlpp11.h>

PostgresTicketRepository::PostgresTicketRepository(
    PostgresDB & _db) : m_db(_db)
{
/*
CREATE TABLE ticket(
  id BIGSERIAL PRIMARY KEY,
  high BIGINT NOT NULL,
  last BIGINT NOT NULL,
  timestamp BIGINT NOT NULL,
  bid BIGINT NOT NULL,
  vwap BIGINT NOT NULL,
  volume BIGINT NOT NULL,
  low BIGINT NOT NULL,
  ask BIGINT NOT NULL,
  open BIGINT NOT NULL
);
*/
}

PostgresTicketRepository::~PostgresTicketRepository()
{
}

void PostgresTicketRepository::insert(const Ticket & _ticket)
{
    sqlpp::postgresql::connection & db = m_db.connection();

    auto tx = start_transaction(db);

    std::stringstream sql;
    sql << "INSERT INTO ticket ("
        << "high, last, timestamp, bid, vwap, volume, low, ask, open"
        << ") VALUES ("
        << _ticket.high() << ", "
        << _ticket.last() << ", "
        << _ticket.timestamp() << ", "
        << _ticket.bid() << ", "
        << _ticket.vwap() << ", "
        << _ticket.volume() << ", "
        << _ticket.low() << ", "
        << _ticket.ask() << ", "
        << _ticket.open() << ") RETURNING id;";

    auto statement = sqlpp::custom_query(sqlpp::verbatim(sql.str()))
      .with_result_type_of(sqlpp::select(sqlpp::value(0).as(sqlpp::alias::a)));

    for(const auto & row : db(statement))
    {
        std::cout << "ID: " << row.a << std::endl;
    }

    tx.commit();
}
