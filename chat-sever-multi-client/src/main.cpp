#include"../inc/main.h"
int main(int argc, char* argv[])
{

	Server sv;
	sv.initsock();
	sv.bindsock();
	sv.listensock();
	sv.acceptsock();
	sv.recvsock();
	cout << endl;
	sv.sendsock();
	cout << endl;
	sv.closesock();
    cout << "Hello word!" << endl;
    return 0;
}
