import discord
import os
import requests
import json
import random
from game_app import TicTacToeApp
from game_engine import TicTacToeTurn

client = discord.Client()

sad_words = ["sad", "depressed", "unhappy", "angry", "miserable"]
starter_encouragements = [
  "Cheer up!",
  "Hang in there.",
  "You are a great person / bot!"
]
knb = [
  "камень",
  "ножницы",
  "бумага"
]
win = {
  "камень":"бумага",
  "ножницы":"камень",
  "бумага":"ножницы",
}
app = TicTacToeApp()

def get_quote():
  response = requests.get("https://zenquotes.io/api/random")
  json_data = json.loads(response.text)
  quote = json_data[0]['q'] + " -" + json_data[0]['a']
  return quote

def d_p(s):
  ans = ''
  ss = s.split()
  for i in ss:
    ans = ans + i
  return ans

@client.event
async def on_ready():
  print('We have logged in as {0.user}'.format(client))

@client.event
async def on_message(message):
  if message.author == client.user:
    return
  msg = message.content
  mss = message.content.split()
  fir = ''
  if message.content.startswith('$hello'):
    await message.channel.send("Hello!")
  elif message.content.startswith('$inspire'):
    quote = get_quote()
    await message.channel.send(quote)
  elif any(word in msg for word in sad_words):
    await message.channel.send(fir+random.choice(starter_encouragements))
  elif message.content.startswith('$commands'):
      await message.channel.send(fir+"I have commands:\n$hello\n$inspire\n$commands\n$help\n$play\n$add_to_server\n$me\n$my_games\n$game_info\n$start_game\n$do_turn\n$new_in_last_version\nAnd if you sand sed message I'll cheer you up")
  elif message.content.startswith('$help'):
    await message.channel.send(fir+"To see commands send $commands")
  elif mss[0] == "$spam":
    if (len(mss) == 2):
      for i in range(int(mss[1])):
        await message.channel.send(fir+"spam")
    if (len(mss) == 3):
      for i in range(int(mss[1])):
        await message.channel.send(fir+mss[2])
  elif message.content.startswith('$add_to_server'):
    await message.channel.send("Click on this link: https://discord.com/api/oauth2/authorize?client_id=826857925292589087&permissions=2148002880&scope=bot to add me to your server")
  elif mss[0] == "$play":
    if (len(mss) != 1) and (mss[1] in knb):
      my = random.choice(knb)
      await message.channel.send(my)
      if (my == mss[1]):
        await message.channel.send("Draw")
      elif (my == win[mss[1]]):
        await message.channel.send("I win")
      else:
        await message.channel.send("You win")
    else:
      await message.channel.send("you need to choise from камень, ножницы or бумага")
  elif msg.startswith('$me'):
      await message.channel.send(str(message.author))
  elif msg.startswith('$my_games'):
      for i in app.all_games_of_user(str(message.author)):
          await message.channel.send(i)
  elif msg.startswith('$game_info'):
      if (len(mss) == 1):
          await message.channel.send("you need specify id")
      else:
        if app.get_game_by_id(mss[1]) == "None":
          await message.channel.send("this game not found")
        else:
          for i in app.get_game_by_id(mss[1]).field:
            await message.channel.send('|'+i[0]+'|'+i[1]+'|'+i[2]+'|')
  elif msg.startswith('$start_game'):
      if (len(mss) == 1):
        await message.channel.send("you need specify second player id")
      else:
        raz = msg.split('"')
        if (len(raz) == 1):
          await message.channel.send("id of second player must be in double quotes")
        else:
          await message.channel.send(app.start_game(str(message.author), raz[1]).game_id)
  elif msg.startswith('$do_turn'):
      if (len(mss) < 4):
        await message.channel.send("you need specify game id, x and y")
      else:
        if (app.get_game_by_id(mss[1]) == "None"):
          await message.channel.send("This game not found")
        else:
          if (int(mss[2]) <= 0):
            await message.channel.send("x must be > 0")
          else:
            if (int(mss[2]) > 3):
              await message.channel.send("x must be < 4")
            else:
              if (int(mss[3]) <= 0):
                await message.channel.send("y must be > 0")
              else:
                if (int(mss[3]) > 3):
                  await message.channel.send("y must be < 4")
                else:
                  if (app.get_game_by_id(mss[1]).first_player_id == str(message.author)) or (app.get_game_by_id(mss[1]).second_player_id == str(message.author)):
                    turn = TicTacToeTurn(str(message.author), int(mss[2])-1, int(mss[3])-1)
                    for i in app.do_turn(turn, mss[1]).field:
                      await message.channel.send('|'+i[0]+'|'+i[1]+'|'+i[2]+'|')
                  else:
                    await message.cannel.send("It isn't your game")
  elif msg.startswith('$new_in_last_version'):
    await message.channel.send("you can play tictactoe game!")

client.run("ODI2ODU3OTI1MjkyNTg5MDg3.YGSlcw.ZqhUOX4Ll3o3olDDrkLciAsuiJk")
