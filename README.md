# YGOPRO replay inflate

Convert ygopro's replay file (.yrp) into json file contains each move.

> this is a demo version, there might be bugs, and I didn't compile/test it on windows.

> also, TAG duels are not supported by now.


## How to build?

### Build requirements

- `cmake >= 3.8.0`
- `sqlite3`
- `gcc` or `clang`
  > minimal version? not sure... as long as it supports c++17

### Build steps

> You can skip this part if you're already familiar with cmake.

``` sh
# clone the repo
git clone https://github.com/ghlin/ygopro-replay-inflate.git

# init submodules
cd ygopro-replay-inflate
git submodule init
git submodule update

# prepare a build folder
mkdir build
cd build

# configure & generate
cmake .. -DCMAKE_INSTALL_PREFIX=$HOME/.local

# build
make
make install

# replay-inflate is now installed to $HOME/.local/bin
```

## How to run the demo?

You need to get [YGOPRO](https://github.com/moecube/ygopro) installed before running this program. 

You can download it from [this page](https://github.com/moecube/ygopro/releases).

``` sh
# Assuming your ygopro is installed to ~/some/where/ygopro
replay-inflate ~/some/where/ygopro/replay/foo.yrp -p ~/some/where/ygopro -o out.json
```

## Example output

> from `misc/test.yrp`, with some modifications to make it readable.

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
```

## What does `MSG_*` mean?

- `misc/message.interface.ts` contains message definitions.
