#include<bits/stdc++.h>
using namespace std;

int findUniqueDeliveryId(const vector<int> &deliveryIds) {
  int uniqueDeliveryId = 0;
  for (auto deliveryId : deliveryIds) {
    uniqueDeliveryId ^= deliveryId;
  }
  return uniqueDeliveryId;
}
