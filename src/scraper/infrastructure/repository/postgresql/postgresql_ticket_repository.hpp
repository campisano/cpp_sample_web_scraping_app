#ifndef POSTGRESQL_TICKET_REPOSITORY__HPP__
#define POSTGRESQL_TICKET_REPOSITORY__HPP__

#include "postgresql_repository_source.hpp"
#include "../../../domain/repositories/ticket_repository.hpp"

class PostgresqlTicketRepository : public TicketRepository
{
public:
    explicit PostgresqlTicketRepository(PostgresqlRepositorySource & _db);
    PostgresqlTicketRepository(const PostgresqlTicketRepository &) = delete;
    PostgresqlTicketRepository(PostgresqlTicketRepository &&) = delete;
    virtual ~PostgresqlTicketRepository();

    virtual void insert(const Ticket & _ticket);

private:
    PostgresqlRepositorySource & m_db;
};

#endif
