#include "postgres_ticket_repository.hpp"

#include <sstream>
#include <sqlpp11/sqlpp11.h>

PostgresTicketRepository::PostgresTicketRepository(
    PostgresDB & _db) : m_db(_db)
{
    /*
    CREATE TABLE ticket(
      id BIGSERIAL PRIMARY KEY,
      timestamp BIGINT NOT NULL,
      low BIGINT NOT NULL,
      high BIGINT NOT NULL,
      last BIGINT NOT NULL,
      bid BIGINT NOT NULL,
      ask BIGINT NOT NULL,
      volume BIGINT NOT NULL,
      source BIGINT NOT NULL
    );
    */
}

PostgresTicketRepository::~PostgresTicketRepository()
{
}

void PostgresTicketRepository::insert(const Ticket & _ticket)
{
    std::stringstream sql;
    sql << "INSERT INTO ticket ("
        << "timestamp, low, high, last, bid, ask, volume, source"
        << ") VALUES ("
        << _ticket.timestamp() << ", "
        << _ticket.low() << ", "
        << _ticket.high() << ", "
        << _ticket.last() << ", "
        << _ticket.bid() << ", "
        << _ticket.ask() << ", "
        << _ticket.volume() << ", "
        << _ticket.source() << ") RETURNING id;";

    auto statement = sqlpp::custom_query(sqlpp::verbatim(sql.str()))
                     .with_result_type_of(sqlpp::select(sqlpp::value(0).as(sqlpp::alias::a)));

    // TODO connection pool or other solution is needed,
    // mutex there is a workaround that works just for this method
    std::lock_guard<std::mutex> lock(m_db_mutex);
    auto & db = m_db.connection();
    auto tx = start_transaction(db);

    for(const auto & row : db(statement))
    {
        std::cout << "ID: " << row.a << std::endl;
    }

    tx.commit();
}
