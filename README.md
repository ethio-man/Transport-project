# TransitFare Calculator: Efficient Public Transport Fare Computation 


A dynamic C++ tool for calculating public transport fares using shortest-path algorithms. Designed for a real but not complete transit network in Addis Ababa/Ethiopia, 
this program computes optimal routes and fares for taxis and buses, complete with animated console interactions.

## Key Features 
- **Shortest-Path Calculation**: Utilizes the Floyd-Warshall algorithm for optimal route discovery.
- **Multi-Transport Pricing**: Supports taxi (5×/km) and bus (4.5×/km) fare calculations.
- **Interactive Console UI**: Features ASCII art banners and animated text displays.
- **Predefined Network**: Includes 10 stations with connectivity constraints (1000 = no direct path).
- **Localized Touch**: Amharic farewell message (`MELKAM GUZO!` – Safe Travels!) for authentic flavor.

## Algorithmic Core 
```cpp
// Floyd-Warshall Implementation
for (int i = 0; i < 10; i++) {
  for (int j = 0; j < 10; j++)
    for (int k = 0; k < 10; k++) {
      if (site.matrix[j][k] > site.matrix[j][i] + site.matrix[i][k]) {
        // Update shortest path and transit station
        site.matrix[j][k] = site.matrix[j][i] + site.matrix[i][k];
        site.stations[j][k] = transit(i);
      }
    }
}
