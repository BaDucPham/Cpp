#include <string>
#include <vector>
#include <iostream>
using namespace std;
string new_state(string state, string event){
  string new_s = "ERROR";
  if (state == "CLOSED") new_s=(event == "APP_PASSIVE_OPEN")?"LISTEN":(event== "APP_ACTIVE_OPEN")?"SYN_SENT":"ERROR";
  if (state == "LISTEN") new_s=(event == "RCV_SYN")?"SYN_RCVD":(event == "APP_SEND")?"SYN_SENT":(event == "APP_CLOSE")?"CLOSED":"ERROR";
  if (state == "SYN_RCVD") new_s=(event == "APP_CLOSE")?"FIN_WAIT_1":(event == "RCV_ACK")?"ESTABLISHED":"ERROR";
  if (state == "SYN_SENT") new_s=(event == "RCV_SYN")?"SYN_RCVD":(event == "RCV_SYN_ACK")?"ESTABLISHED":(event == "APP_CLOSE")?"CLOSED":"ERROR";
  if (state == "ESTABLISHED") new_s=(event == "APP_CLOSE")?"FIN_WAIT_1":(event == "RCV_FIN")?"CLOSE_WAIT":"ERROR";
  if (state == "FIN_WAIT_1") new_s=(event == "RCV_FIN")?"CLOSING":(event == "RCV_FIN_ACK")?"TIME_WAIT":(event == "RCV_ACK")?"FIN_WAIT_2":"ERROR";
  if (state == "CLOSING") new_s=(event == "RCV_ACK")?"TIME_WAIT":"ERROR";
  if (state == "FIN_WAIT_2") new_s=(event == "RCV_FIN")?"TIME_WAIT":"ERROR";
  if (state == "TIME_WAIT")  new_s=(event == "APP_TIMEOUT")?"CLOSED":"ERROR";
  if (state == "CLOSE_WAIT")  new_s=(event == "APP_CLOSE")?"LAST_ACK":"ERROR";
  if (state == "LAST_ACK")  new_s=(event == "RCV_ACK")?"CLOSED":"ERROR";
  return new_s;
}

string traverse_TCP_states(const vector<std::string> &events){
  string state = "CLOSED";
  cout << "\nTest\n";
  for (auto event: events){
    cout << state << " " << event << " ";
    state = new_state(state,event);
    cout << state << endl;
    if (state == "ERROR") return "ERROR";
  }
  return state;
}

int main(){
    vector<string> events = {"APP_PASSIVE_OPEN", "APP_SEND", "RCV_SYN_ACK"};
    cout << traverse_TCP_states(events) << endl;
}