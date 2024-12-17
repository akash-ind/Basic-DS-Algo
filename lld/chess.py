"""
Board Constant
Class Players


Class Match


Class Elements:

Sub Class of Pawns, Bishops

Class Board:
    init

"""


class Player:

    def __init__(self, name) -> None:
        self.name = name

class Element:

    def __init__(self, name, color) -> None:
        self.name = name
        self.color = color

    def is_move_possible(initial, final) -> bool:
        pass

# Subclasses of Element: like

# class Pawn(Element):
#     pass

class Board:

    def __init__(self) -> None:
        self.board = [[None]*8]*8
        self.intialise_board()

    
    def intialise_board(self):
        for i in range(8):
            el = Element("pawn", "white")
            self.board[1][i] = el
            el = Element("pawn", "black")
            self.board[6][i] = el

        for i in range(2):
            el = Element("elephant", "white")
            self.board[0][i] = el
            # this way we can initialize
        pass

    def make_move(self, initial_pos: list, final_pos: list, color: str):
        r, c = initial_pos
        final_r, final_c = final_pos
        if r < 0 or c < 0 or r>=8 or c>=8 or final_r < 0 or final_c < 0 or final_r >=8 or final_c >= 8:
            raise Exception("Wrong positions entered")

        if self.board[r][c] is None:
            raise Exception("Element not present on initial position")
        
        if self.board[r][c].color != color:
            raise Exception("Cannot move another color")
        
        if self.board[final_r][final_c] is not None:
            # match for the color
            pass

        el = self.board[r][c]

        if el.is_move_possible(initial_pos, final_pos):
            
            self.board[r][c] = None
            self.board[final_r][final_c] = el

        return True
    
    def is_checkmate(self):
        pass

    def get_winner(self):  # return color or None
        pass

    def is_draw(self):
        pass


class Match:

    def __init__(self, player1, player2) -> None:
        self.player1 = player1
        self.player2 = player2

        self.board = Board()

        self.colors = {
            "white": player1,  # color can be enum
            "black": player2
        }

    def get_move(self):
        return [0, 1], [2, 3]  # initial and final pos

    def start_game(self):
        start = "white"
        while not (self.board.is_checkmate() or self.board.is_draw()):
            initial_pos, final_pos = self.get_move()

            self.board.make_move(initial_pos, final_pos, start)

            start = "black" if start == "white" else "white"

        if self.is_draw():
            return "DRAW"
        else: 
            return self.board.get_winner()




