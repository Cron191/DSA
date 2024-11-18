import pygame
import random

# Kích thước màn hình
SCREEN_WIDTH = 600
SCREEN_HEIGHT = 400
BLOCK_SIZE = 20  # kích thước mỗi ô (khối)

# Màu sắc
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)
RED = (255, 0, 0)

# Lớp quản lý Rắn
class Snake:
    def __init__(self):
        self.body = [(100, 100)]  # thân rắn, khởi tạo với một ô
        self.direction = (BLOCK_SIZE, 0)  # ban đầu đi sang phải

    def move(self):
        # Di chuyển thân rắn
        head_x, head_y = self.body[0]
        dir_x, dir_y = self.direction
        new_head = (head_x + dir_x, head_y + dir_y)
        self.body = [new_head] + self.body[:-1]

    def grow(self):
        # Thêm một phần thân cho rắn
        self.body.append(self.body[-1])

    def change_direction(self, new_direction):
        # Đổi hướng, đảm bảo không quay ngược 180 độ
        dir_x, dir_y = self.direction
        new_x, new_y = new_direction
        if (dir_x, dir_y) != (-new_x, -new_y):  # kiểm tra không ngược chiều
            self.direction = new_direction

    def check_collision(self):
        # Kiểm tra va chạm bản thân
        head = self.body[0]
        return head in self.body[1:]

# Lớp quản lý thức ăn
class Food:
    def __init__(self):
        self.position = (random.randint(0, (SCREEN_WIDTH - BLOCK_SIZE) // BLOCK_SIZE) * BLOCK_SIZE,
                         random.randint(0, (SCREEN_HEIGHT - BLOCK_SIZE) // BLOCK_SIZE) * BLOCK_SIZE)

    def respawn(self):
        # Sinh thức ăn ở vị trí mới
        self.position = (random.randint(0, (SCREEN_WIDTH - BLOCK_SIZE) // BLOCK_SIZE) * BLOCK_SIZE,
                         random.randint(0, (SCREEN_HEIGHT - BLOCK_SIZE) // BLOCK_SIZE) * BLOCK_SIZE)

# Lớp quản lý trò chơi chính
class Game:
    def __init__(self):
        pygame.init()
        self.screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
        pygame.display.set_caption("Snake Game")
        self.clock = pygame.time.Clock()
        self.snake = Snake()
        self.food = Food()
        self.score = 0
        self.running = True

    def check_food_collision(self):
        # Kiểm tra va chạm giữa rắn và thức ăn
        if self.snake.body[0] == self.food.position:
            self.snake.grow()
            self.food.respawn()
            self.score += 1

    def check_wall_collision(self):
        # Kiểm tra va chạm với tường
        head_x, head_y = self.snake.body[0]
        return head_x < 0 or head_x >= SCREEN_WIDTH or head_y < 0 or head_y >= SCREEN_HEIGHT

    def handle_events(self):
        # Xử lý các sự kiện bàn phím
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    self.snake.change_direction((0, -BLOCK_SIZE))
                elif event.key == pygame.K_DOWN:
                    self.snake.change_direction((0, BLOCK_SIZE))
                elif event.key == pygame.K_LEFT:
                    self.snake.change_direction((-BLOCK_SIZE, 0))
                elif event.key == pygame.K_RIGHT:
                    self.snake.change_direction((BLOCK_SIZE, 0))

    def update(self):
        # Cập nhật trạng thái trò chơi
        self.snake.move()
        if self.check_wall_collision() or self.snake.check_collision():
            self.running = False  # Kết thúc trò chơi nếu va chạm
        self.check_food_collision()

    def draw(self):
        # Vẽ các thành phần lên màn hình
        self.screen.fill(BLACK)
        # Vẽ thân rắn
        for segment in self.snake.body:
            pygame.draw.rect(self.screen, GREEN, (*segment, BLOCK_SIZE, BLOCK_SIZE))
        # Vẽ thức ăn
        pygame.draw.rect(self.screen, RED, (*self.food.position, BLOCK_SIZE, BLOCK_SIZE))
        # Hiển thị điểm
        font = pygame.font.Font(None, 36)
        score_text = font.render(f"Score: {self.score}", True, WHITE)
        self.screen.blit(score_text, (10, 10))
        pygame.display.flip()

    def run(self):
        # Vòng lặp chính của trò chơi
        while self.running:
            self.handle_events()
            self.update()
            self.draw()
            self.clock.tick(10)  # Tốc độ game

# Khởi tạo và chạy trò chơi
if __name__ == "__main__":
    game = Game()
    game.run()
    pygame.quit()
