int ovenTime() { return 40; }

int remainingOvenTime(int actualMinutesInOven) {
  return ovenTime() - actualMinutesInOven;
}

int preparationTime(int numberOfLayers) { return 2 * numberOfLayers; }

int elapsedTime(int numberOfLayers, int actualMinutesInOven) {
  return actualMinutesInOven + preparationTime(numberOfLayers);
}