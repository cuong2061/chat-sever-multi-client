#include"../inc/main.h"
int main(int argc, char* argv[])
{
	if(strcmp(argv[1], "1") == 0)
	{
		cout << "=====================Start Server=====================" << endl;
		Server sv;
		sv.initsock();
		sv.bindsock();
		sv.listensock();
		sv.acceptsock();
		sv.recvsock();
		sv.sendsock();
		sv.closesock();
	}
	else{
		cout << "=====================Start Client=====================" << endl;
		Client cl;
		cl.initsock();
		cl.connectsock();
		cl.sendsock();
		cl.recvsock();
		cl.closesock();
	}
	cout << "========================End===========================" << endl;
    return 0;
}
