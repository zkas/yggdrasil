//params_xml_serialization.hpp

#include <cassert>
#include <iostream>
#include <vector>
#include <string>

#include <boost/serialization/access.hpp>

#include <yggr/archive/bson_archive_partner.hpp>
#include <yggr/base/yggrdef.h>
#include <yggr/packet/packet.hpp>

#include <yggr/any_val/any.hpp>
#include <yggr/serialization/any.hpp>


// warning: mingw use libboost_serialization-mgw47-mt-1_53.a //fix xml_gamma_error

#ifdef _MSC_VER
#   include <vld.h>
#endif //_MSC_VER

typedef yggr::packet::packet<yggr::archive::archive_partner::bson_oarchive_partner> opak;
typedef yggr::packet::packet<yggr::archive::archive_partner::bson_iarchive_partner> ipak;

void test_foo1(void)
{
	yggr::any any1(10);

	opak o;
	o.save(YGGR_SERIALIZE_NAME_NVP("any", any1));

	std::cout << o.org_buf() << std::endl;

	ipak i(o);
	yggr::any any2;

	i.load(YGGR_SERIALIZE_NAME_NVP("any", any2));

	assert(yggr::any_cast<int>(any2) == yggr::any_cast<int>(any1));
}

int main(int argc, char* argv[])
{
	test_foo1();

	char cc = 0;
	std::cin >> cc;
	return 0;
}