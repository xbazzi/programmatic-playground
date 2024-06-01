"""
Tic Tac Toe Player
"""

from json.encoder import INFINITY
import copy

X = "X"
O = "O"
EMPTY = None


def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """
    counter = 0
    for row in board:
        for cell in row:
            if cell is not None:
                counter += 1
    if counter % 2 == 0:
        return "X"
    return "O"


def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """

    i = 0
    possible_actions = set()
    for row in board:
        j = 0
        for cell in row:
            if cell is EMPTY:
                possible_actions.add((i, j))
            j += 1
        i += 1
    return possible_actions


def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """

    # check if action is valid
    if action not in actions(board):
        raise Exception('Not a valid action on this board.')

    board_copy = copy.deepcopy(board)

    # perform action on copied board
    i, j = action
    board_copy[i][j] = player(board)
    return board_copy


def winner(board):
    """
    Returns the winner of the game, if there is one.
    """

    # check diagonals
    if board[0][0] == board[1][1] == board[2][2] and board[1][1] is not None:
        return board[1][1]
    if board[0][2] == board[1][1] == board[2][0] and board[1][1] is not None:
        return board[1][1]
    # check horizontals
    for i in range(len(board)):
        if board[i][0] == board[i][1] == board[i][2] and board[i][0] is not None:
            return board[i][0]
    # check verticals
    for i in range(len(board)):
        if board[0][i] == board[1][i] == board[2][i] and board[0][i] is not None:
            return board[0][i]
    return None


def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """

    # check is there is a winner
    if winner(board) is not None:
        return True
    # check for empty cells
    for row in board:
        for cell in row:
            if cell is None:
                return False
    return True


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    You may assume utility will only be called on a board if terminal(board) is True
    """

    if winner(board) == X:
        return 1
    elif winner(board) == O:
        return -1
    else:
        return 0  # tie

# maximizes the value of alpha


def max_value(board, alpha, beta):
    v = -INFINITY
    if terminal(board):
        return utility(board)
    for action in actions(board):
        v = max(v, min_value(result(board, action), alpha, beta))
        # alpha-beta pruning
        alpha = max(alpha, v)
        if alpha >= beta:
            break
    return alpha

# minimizes the value of beta


def min_value(board, alpha, beta):
    v = INFINITY
    if terminal(board):
        return utility(board)
    for action in actions(board):
        v = min(v, max_value(result(board, action), alpha, beta))
        # alpha-beta pruning
        beta = min(beta, v)
        if alpha >= beta:
            break
    return beta


def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    The move returned should be the optimal action (i, j) that is one of the allowable actions on the board. 
    If multiple moves are equally optimal, any of those moves is acceptable.
    """
    # initial alpha-beta pruning values
    alpha = -INFINITY
    beta = INFINITY

    if terminal(board):
        return None

    # player X
    elif player(board) == X:
        plays = []
        for action in actions(board):
            plays.append(
                [min_value(result(board, action), alpha, beta), action])
        # Reverse sort for the plays list and get the action that should take
        return sorted(plays, key=lambda x: x[0], reverse=True)[0][1]

    # player O
    elif player(board) == O:
        plays = []
        for action in actions(board):
            plays.append(
                [max_value(result(board, action), alpha, beta), action])
        return sorted(plays, key=lambda x: x[0])[0][1]

