document.addEventListener('DOMContentLoaded', function () {
    const board = document.getElementById('ticTacToeBoard');
    const cells = board.querySelectorAll('td');
    let currentPlayer = 'X';
    let gameBoard = ['', '', '', '', '', '', '', '', ''];
    let gameActive = true;

    function checkWinner() {
        const winPatterns = [
            [0, 1, 2], [3, 4, 5], [6, 7, 8], // Rows
            [0, 3, 6], [1, 4, 7], [2, 5, 8], // Columns
            [0, 4, 8], [2, 4, 6]             // Diagonals
        ];

        for (const pattern of winPatterns) {
            const [a, b, c] = pattern;
            if (gameBoard[a]  === gameBoard[b] && gameBoard[a] === gameBoard[c]) {
                return gameBoard[a];
            }
        }

        return null;
    }

    function handleCellClick(index) {
        if (!gameActive || gameBoard[index] !== '') {
            return;
        }

        gameBoard[index] = currentPlayer;
        cells[index].innerText = currentPlayer;

        const winner = checkWinner();
        if (winner) {
            alert(`Player ${winner} wins!`);
            gameActive = false;
        } else if (!gameBoard.includes('')) {
            alert('It\'s a tie!');
            gameActive = false;
        } else {
            currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
        }
    }

    cells.forEach((cell, index) => {
        cell.addEventListener('click', () => handleCellClick(index));
    });
});
