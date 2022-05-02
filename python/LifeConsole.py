from datetime import datetime as dt


def su_say(s):
    su_prompt = 'Su Say: '
    print(f'{su_prompt}{s}')

class LifeConsole:

    def time(self, arg):
        su_say(dt.now().strftime("%H:%M:%S"))

    def date(self, arg):
        su_say(dt.now().strftime("%Y/%m/%d %H:%M:%S"))

    def hello(self,arg):
        su_say("Hello !!")



