#include "pimpl.hpp"

struct Model
{
	int get_bread() { return 5; }
};

Api::Api() : m_mod(new Model) {}
Api::~Api() { delete m_mod; }

int Api::get_bread()
{
	return m_mod->get_bread();
}
