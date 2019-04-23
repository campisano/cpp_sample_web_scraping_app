#ifndef POSTGRESQL_TICKET_REPOSITORY__HPP__
#define POSTGRESQL_TICKET_REPOSITORY__HPP__

#include "../../../repository/ticket_repository.hpp"
#include "postgresql_repository.hpp"

class PostgresqlTicketRepository : public TicketRepository
{
public:
    explicit PostgresqlTicketRepository(PostgresqlRepository & _db);
    PostgresqlTicketRepository(const PostgresqlTicketRepository &) = delete;
    PostgresqlTicketRepository(PostgresqlTicketRepository &&) = delete;
    virtual ~PostgresqlTicketRepository();

    virtual void insert(const Ticket & _ticket);

private:
    PostgresqlRepository & m_db;
};

#endif
