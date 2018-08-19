# YGOPRO replay inflate

converts ygopro's replay file (.yrp) into json file contains each move.

## demo

see `demo/README.md"

## example output

``` json
{
  "config": {
    "draw_count": 1,
    "duel_rule": 262144,
    "start_hand": 5,
    "start_lp": 8000
  },
  "header": {
    "hash": 72911400,
    "id": 829452921,
    "version": 4931
  },
  "players": [
    {
      "deck": {
        "extra": [ 86938484, 50588353, 15844566 ],
        "main": [ "..." ]
      },
      "name_buffer": [ 70, 105, 114, 122, 101, 110, 0, "..." ]
    },
    {
      "deck": {
        "extra": [ "..." ],
        "main": [ "..." ]
      },
      "name_buffer": [ 71, 104, 108, 105, 110, 0, "..." ]
    }
  ],
  "records": [
    {
      "data": {
        "cards": [
          { "code": 44394295 },
          { "code": 57774843 },
          { "code": 78474168 },
          { "code": 73176465 },
          { "code": 4904633 }
        ],
        "player": 0
      },
      "type": "MSG_DRAW"
    },
    {
      "data": {
        "cards": [
          { "code": 92435533 },
          { "code": 51452091 },
          { "code": 51452091 },
          { "code": 27107590 },
          { "code": 74530899 }
        ],
        "player": 1
      },
      "type": "MSG_DRAW"
    },
    {
      "data": { "player": 0 },
      "type": "MSG_NEW_TURN"
    },
    {
      "data": { "phase": 1 },
      "type": "MSG_NEW_PHASE"
    },
    {
      "data": { "phase": 2 },
      "type": "MSG_NEW_PHASE"
    },
    {
      "data": { "phase": 4 },
      "type": "MSG_NEW_PHASE"
    },
    "..."
  ]
}
